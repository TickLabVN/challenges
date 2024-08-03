# GitHub organization metrics

## I. Overview
This project focuses on building a user-friendly tool that automates the creation of visually appealing and customizable GitHub organizational profiles, rendered entirely in SVG (Scalable Vector Graphics) format.

## II. What you can receive
- Learn how to use [Octokit.js](https://github.com/octokit/octokit.js) to interact with the GitHub REST API in your JavaScript scripts.
- Learn how to build a tool using GitHub Actions.
- Learn how to contribute to open source software.
- Receive mentorship throughout the challenge.

### III. Technology
- Javascript/Typescript
- CI/CD (Github Actions)
- Github SDK

## IV. Target Users
This tool empowers GitHub organizations to streamline the creation of their profiles.

## V. Key Features
Export the following information as SVG to embed in the README file for data visualization.
1. Base content, the following sections are supported:
    - `header`: which usually contains organization name and a few additional data.
    - `community`: which contains community stats (following, sponsors, etc.).
    - `repositories`: which contains repository stats (license, forks, stars, etc.).

    These are all enabled by default, but it is possible to explicitly opt out from them.

2. Programming languages used by organization members.
3. Stargazers evolution across affiliated repositories (total stargazers, new stargazers per day).
4. Coding habits based on recent activity, such as active hours and languages recently used.
5. Ratio of open/closed issues and the ratio of open/merged pull requests across repositories.
6. Recent activity on GitHub. Events types are fetched from [GitHub events API](https://docs.github.com/en/rest/using-the-rest-api/github-event-types) and the following types are currently supported:
    - `push`: Push of commits.
    - `issue`: Opening/Reopening/Closing of issues.
    - `pr`: Opening/Closing of pull requests.
    - `release`: Publication of new releases.
    - `review`: Review of pull requests.
    - `comment`: Comments on commits, issues and pull requests.
    - `fork`: Forking of repositories.
    - `star`: Starring of repositories.
    - `public`: Repositories made public.
    - `member`: Addition of new collaborator in repository.
7. Github projects.

## VI. References
- An infographics generator to display stats about your GitHub account: [https://github.com/lowlighter/metrics](https://github.com/lowlighter/metrics).
- A tool to generate your github summary card for profile README: [https://github.com/vn7n24fzkq/github-profile-summary-cards](https://github.com/vn7n24fzkq/github-profile-summary-cards).
