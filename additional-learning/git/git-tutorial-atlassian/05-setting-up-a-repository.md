## Setting up a repository

Git repo is a virtual storage of your project. It allows you to save versions of your code, which you can access when needed. 

To create a repo, use `git init` command, this create .git subdir and a master branch.

---

To copy an already set up central repo, use `git clone <repo url>`.

The new repo has full history, (only) has master branch, and is configured with a remote pointed to the Git URL you cloned it from.

(Repo created with "git init" doesn't have remote repo to push changes to.)

---

Template of Git SSH protocal:

```
git@hostname:username/reponame.git
(git@github.com:nhannguyen95/interview-preparation.git)
```

The new repo has full history, (only) has master branch, and is configured with a remote pointed to the Git URL you cloned it from.

---

To add untracked files to the repo, use `git add`.

---

Git stores configuration options in three separate files, which lets you scope options to individual repositories (local), user (Global), or the entire system (system):

- Local: `<repo>/.git/config` – Repository-specific settings.
- Global: `/.gitconfig` – User-specific settings. This is where options set with the --global flag are stored.
- System: `$(prefix)/etc/gitconfig` – System-wide settings.

---

To create shortcut for Git command (I.e. use `git ci` instead of `git commit`):

```
git config --global alias.ci commit
```

## git init

`git init` inside a folder that already has .git folder won't change the existing .git configuration be changed.

---

**Bare repos** are central repos, used to `git push` and `git pull` from (but may never directly commit to it). Like repos on Github.

**Non-bare** repos are developers local repos.

---

To create a remote central repo:
- ssh into server that will contain your central repo: `ssh <user>@<host>`
- Navigate to where you like to store the project: `cd path`
- `git init --bare <project_name>`


## git clone

The "origin" created when you `git clone` from a repo is a remote connection pointing back to that repo (the original repo).

---

To shallow copy in Git:

```
`git clone -depth=1 <repo>
```

`depth` is the number of most recent commits that are included in the new cloned repo.

---

`git clone` clone ony the master branch by default because the remote HEAD is pointing to is usually the master branch.

To clone a specific branch:

```
git clone -branch <branch_name> <repo>
```

---

Git URL protocols are Git's own URL syntax which is used to pass remote repo locations to Git commands:
- SSH: since it an authenticated protocol, you'll need to establish credentials with hosting server: `ssh://[user@]host.xz[:port]/path/to/repo.git/`
- Git: no authentication: `git://host.xz[:port]/path/to/repo.git/`
- HTTP(s): `http[s]://host.xz[:port]/path/to/repo.git/`

## git config

To specify a merge tool for Git:

```
git config --global merge.tool <merge_tool>
```

`<merge_tool>` can be kdiff3

## git alias

2 ways to create Git Aliases:
- Edit to global or local config file:

```
[alias]
co = checkout
```

- Use git command:

```
git config --global alias.co checkout
```
