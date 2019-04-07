## Undo a public commit with `git revert`

Suppose we have:

```
git log --oneline
872fa7e Try something crazy
a1e8fb5 Abc
```

`git revert HEAD` will create a new commit with the inverse of the last commit. This adds a new commit to the current branch history and now makes it look like:

```
git revert HEAD (this will open editor for entering commit message, to avoid:)
git revert HEAD --no-edit

git log --oneline
e2f9a78 Revert "Try something crazy"
872fa7e Try something crazy
a1e8fb5 Abc
```

Passing `--no-commit` or `-n`  will prevent git revert from creating a new commit that inverses the target commit. Instead of creating the new commit this option will add the inverse changes to the Staging Index and Working Directory:

```
git revert HEAD --no-commit
```

This is the ideal 'undo' method for working with public shared repositories, since it doesn't alter the repo history (from 872fa7e to previous ones).

If you have requirements of keeping a curated and minimal Git history this strategy may not be satisfactory.

## Undo a commit with `git reset`

Three internal trees of Git:
- The commit history (with HEAD refs points to the most recent commit by default)) - the **committed** state. The files are in `.git directory`.
- The staging tree (changes that are ready for the next commit) - the **staged** state. The files are in **staging area** (or **index**).
- The working directory (tracked files) - the **modified** state. The files are in **working directory** (or **working tree**).

Supose we have made 4 commits to master branch:

```
[a]--[b]--[c]--[d] <- HEAD ref, branch ref pointing to d
```

When use `git checkout b`:

```
[a]--[b]--[c]--[d] <- branch ref
      ^
      |
     HEAD
```

When use `git reset b`:

```
[a]--[b]    [c]--[d]
      ^
      |
 HEAD, branch ref
```

### `git reset --hard <hash_commit, default=HEAD>`, scoped to Commit History

If we invoke git `reset --hard a1e8fb5` the commit history is reset to that specified commit. Any previously pending changes to the Staging Index and the Working Directory gets reset to match the state of the Commit Tree. This means any pending work that was hanging out in the Staging Index and Working Directory will be lost (this cannot be undone).

### `git reset --mixed <hash_commit, default=HEAD>`, scoped to Working Directory

`git reset --mixed HEAD` is default to `git reset`.

The Staging Index is reset to the state of the specified commit. Any changes that have been undone from the Staging Index are **moved to the Working Directory**. Let us continue.

Just a side note: to remove the specified file from the staging area, but leave the working deirectory unchanged:

```
git reset <file>
```

### `git reset --soft <hash_commit, default=HEAD>`, scoped to Staging Index

Let's say we want to reset back to the commit `abc`, doing `git reset --soft abc` will move the HEAD ref to that commit. The changes that are lying in the subsequence commits from `abc` (that are the commits that we are about to remove) will be **moved to Staging Index**.

<img src="https://i.stack.imgur.com/qRAte.jpg" />

---

Note: Doing a reset is great for local changes, but not for shared remote repo. If we have a shared remote repository that has the 872fa7e commit pushed to it, and we try to git push a branch where we have reset the history, Git will catch this and throw an error. In these scenarios, git revert should be the preferred undo method. So don't reset public history.
 
 
## Undoing the last commit

You can add changes to last commit:

```
git add
git commit --amend (Git will open the editor and let you modify last commit message)
```

## Undoing uncommitted changes

You may need to undo changes within staging index and the working directory (use `git reset`).

## Undoing changes in the working directory with `git clean`

If `git reset` and `git revert` are performed on tracked files, then `git clean` is performed on untracked ones.

To remove all untracked files in the working dir (but not untracked folders and ignored files):

```
git clean -f
```

To remove also any untracked folders:

```
git clean -df
```

Run in "dry run" mode: 

```
$ git clean -n
Would remove untracked_file
```

Interactive mode:

```
git clean -i
(or git clean -di)
```

## `git rm`

`git rm` can be used to remove files from the Index, or from the Working Tree and the Index. 

Some flags:
- `-r`: If there is a discrepency between the HEAD version of a file (that we are about to remove) and the staging index or working tree version, Git will by default block the removal. Use this to override that safety check.
- `--cached`: The cached option specifies that the removal should happen only on the staging index. Working directory files will be left alone.

Note: If you just use rm, you will need to follow it up with `git add <fileRemoved>`.  `git rm` does this in one step.

To remove files in Commit History (Git repo) to Untracked:

```
git rm <files>
```

To remove files in Staging Index to Untracked:

```
git rm --cached <files>
```

To remove a directory and all its content:

```
git rm -r <directory>
```


