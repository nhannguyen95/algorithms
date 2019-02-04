## Saving Changes

Saving ~ Committing.

## git add, git reset, git commit, git push

First, you edit your files in the working directory.

The `git add` command adds a change in the working directory to the staging area.

Changes are not actually recorded until you run `git commit` (commit a snapshot of the staging directory to the repositories commit history).

The `git reset` command is used to undo a commit or staged snapshot (undo `git add`).

`git push` is utilized to send the committed changes to remote repositories for collaboration. This enables other team members to access a set of saved changes.

---

It helps to think of **staging area** as a buffer between the working directory and the project history. The staging area is considered one of the "three trees" of Git, along with, the working directory, and the commit history.

When you commit, you commit things in staging area => stanging area helps group related changes into highly focused snapshots before actually committing it to the project history.

## git diff

Compare 1 specific file in working directory (the file is added and modified) against the index HEAD (the most recent commit):

```
git diff HEAD ./path/to/file
= git diff ./path/to/file (since HEAD is chosen by default)
```

Compare 1 specific file in staging area (the file is added and committed) against the (most recent commit of) local repo:

```
git diff --cached ./path/to/file
```

Remove the file path to compare all changes.

Every commit in Git has a commit ID which you can get when you execute `git log`. You can also pass this commit ID to git diff:

```
git diff 957fbc92b123030c389bf8b4b874522bdf2db72c ce489262a1ee34340440e55a0b99ea6918e19e7a
```

Compare 2 (tips of) branches:

```
git diff branch1 branch2
(or git diff branch1..branch2)
```

Compare shared common ancestor commit between branch1 and branch 2 to branch 2:

```
git diff branch1...branch2
```

Compare files from 2 branches:

```
git diff branch1 branch2 file_name
```

## git stash

The `git stash` command takes your uncommitted changes _(both staged and unstaged)_, saves them away for later use, and then reverts them from your working copy:

```
$ git status
On branch master
Changes to be committed:
new file: style.css
Changes not staged for commit:
modified: index.html

$ git stash
...

$ git status
On branch master
nothing to commit, working tree clean
```

_Note: stash is local to your Git repository; stashes are not transferred to the server when you push._

Removes the changes from your stash and reapplies them to your working copy:

```
git stash pop
```

Reapplies but don't remove from stash:

```
git stash apply
```

This is useful if you want to apply the same stashed changes to multiple branches.

By default, `git stash` will only stash tracked files:
- changes that have been added to your index (staged changes)
- changes made to files that are currently tracked by Git (unstaged changes)

But it will not stash:
- new files in your working copy that have not yet been staged (i.e: untracked files, we don't run `git add`)
- files that have been ignored

To stash untracked files:

```
git stash -u
= git stash --include-untracked
```

To stash ignore files:

```
git stash -a
= git stash --all
```

Read more: https://www.atlassian.com/git/tutorials/saving-changes/git-stash

## .gitignore

Git sees every file in your working copy as one of three things:
- tracked - a file which has been previously staged or committed.
- untracked - a file which has not been staged or committed.
- ignored - a file which Git has been explicitly told to ignore.

Some Git ignore patterns:
- `logs` or `**/logs`: ignore all logs files and folders (a double asterisk matches zero or more directories).
- `logs/`: ignore logs folders.
- `debug.log`: by default, patterns match files in any directory.
- `*.log \n !important.log`: ignore all .log file except `important.log`.
- `/debug.log`: prepending a slash matches files only in the repository root.
- `logs/debug.log`: patterns specifying a file in a particular directory are relative to the repository root, thus this ignores `logs/debug.log` but not `build/logs/debug.log`.

Global Git ignore rules:

```
$ touch ~/.gitignore
$ git config --global core.excludesFile ~/.gitignore
```

Force an ignored file to be committed to the repository:

```
git add -f debug.log (-f = --force)
```

To debug which pattern causes a particular file to be ignored:

```
git check-ignore -v debug.log (-v = --verbose)
```

