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

 If we invoke git `reset --hard a1e8fb5` the commit history is reset to that specified commit:
 
 ```
 git log --oneline
 a1e8fb5 Abc
 ```
 
 Doing a reset is great for local changes, but not for shared remote repo. If we have a shared remote repository that has the 872fa7e commit pushed to it, and we try to git push a branch where we have reset the history, Git will catch this and throw an error. In these scenarios, git revert should be the preferred undo method.
 
 
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



