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



