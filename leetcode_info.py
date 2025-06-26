#!/usr/bin/env python3
import requests
import argparse

def get_leetcode_profile(username):
    url = 'https://leetcode.com/graphql'
    headers = {
        'Content-Type': 'application/json',
        'Referer': f'https://leetcode.com/{username}/'
    }

    query = {
        "operationName": "getUserProfile",
        "variables": {"username": username},
        "query": """
        query getUserProfile($username: String!) {
          matchedUser(username: $username) {
            username
            profile {
              realName
              ranking
              reputation
              starRating
            }
            submitStats {
              acSubmissionNum {
                difficulty
                count
              }
            }
          }
        }
        """
    }

    res = requests.post(url, headers=headers, json=query)
    data = res.json()

    user = data['data'].get('matchedUser')
    if not user:
        print(f"User '{username}' not found.")
        return

    profile = user['profile']
    stats = user['submitStats']['acSubmissionNum']

    print(f"\n📄 LeetCode Profile: {username}")
    print(f"🏅 Ranking: {profile['ranking']}")
    print(f"✨ Reputation: {profile['reputation']}")
    print(f"⭐ Star Rating: {profile['starRating']}")
    print("\n📊 Solved Problems:")
    for item in stats:
        print(f"  {item['difficulty']}: {item['count']} problems")

def get_recent_submissions(username):
    url = 'https://leetcode.com/graphql'
    headers = {
        'Content-Type': 'application/json',
        'Referer': f'https://leetcode.com/{username}/'
    }

    query = {
        "operationName": "getRecentSubmissionList",
        "variables": {"username": username},
        "query": """
        query getRecentSubmissionList($username: String!) {
          recentSubmissionList(username: $username) {
            title
            statusDisplay
            lang
            time
          }
        }
        """
    }

    res = requests.post(url, headers=headers, json=query)
    data = res.json()

    submissions = data['data'].get('recentSubmissionList', [])
    print(f"\n🕓 Recent Submissions for {username}:")
    for sub in submissions[:5]:
        print(f"  {sub['title']} | {sub['lang']} | {sub['statusDisplay']}")

def main():
    parser = argparse.ArgumentParser(description="View LeetCode profile and recent submissions.")
    parser.add_argument('--user', type=str, required=True, help='LeetCode username')

    args = parser.parse_args()
    get_leetcode_profile(args.user)
    get_recent_submissions(args.user)

if __name__ == "__main__":
    main()
