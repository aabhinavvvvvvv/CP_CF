#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

void show_permissions(mode_t mode) {
    char perms[11];
    perms[0] = S_ISDIR(mode) ? 'd' : '-';
    perms[1] = (mode & S_IRUSR) ? 'r' : '-';
    perms[2] = (mode & S_IWUSR) ? 'w' : '-';
    perms[3] = (mode & S_IXUSR) ? 'x' : '-';
    perms[4] = (mode & S_IRGRP) ? 'r' : '-';
    perms[5] = (mode & S_IWGRP) ? 'w' : '-';
    perms[6] = (mode & S_IXGRP) ? 'x' : '-';
    perms[7] = (mode & S_IROTH) ? 'r' : '-';
    perms[8] = (mode & S_IWOTH) ? 'w' : '-';
    perms[9] = (mode & S_IXOTH) ? 'x' : '-';
    perms[10] = '\0';

    printf("Permissions : %s\n", perms);
}

void describe_entry(const char *filepath) {
    struct stat info;
    if (lstat(filepath, &info) == -1) {
        perror("lstat");
        return;
    }

    printf("→ %s\n", filepath);
    printf("Kind       : %s\n", S_ISDIR(info.st_mode) ? "Directory" : "Regular File");

    show_permissions(info.st_mode);

    struct passwd *owner = getpwuid(info.st_uid);
    struct group *grp = getgrgid(info.st_gid);

    printf("Owner      : %s\n", owner ? owner->pw_name : "Unknown");
    printf("Group      : %s\n", grp ? grp->gr_name : "Unknown");
    printf("Last Access: %s", ctime(&info.st_atime));
    printf("Last Modify: %s", ctime(&info.st_mtime));
    printf("Last Change: %s", ctime(&info.st_ctime));
    puts("---------------------------------------");
}

void explore_dir(const char *base, const char *target) {
    DIR *dp = opendir(base);
    if (!dp) return;

    struct dirent *entry;
    while ((entry = readdir(dp)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        char fullpath[1024];
        snprintf(fullpath, sizeof(fullpath), "%s/%s", base, entry->d_name);

        if (strcmp(entry->d_name, target) == 0) {
            describe_entry(fullpath);
        }

        if (entry->d_type == DT_DIR) {
            explore_dir(fullpath, target);
        }
    }
    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <directory> <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    explore_dir(argv[1], argv[2]);
    return EXIT_SUCCESS;
}
