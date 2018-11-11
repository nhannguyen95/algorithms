## git status

## git log

Limits commit history:

```
git log -n <limit>
```

Condense each commit to a single line:

```
git log --oneline
```

Include which files were altered:

```
git log --stat
```

Filter:

```
git log --author="<pattern>"
git log --grep="<pattern>"
git log <since>..<until>
(Both arguments can be either a commit ID, a branch name, HEAD)
```

Only display commits that include the specified file:

```
git log <file>
```

Shows the full diff of each commit:

```
git log -p
```

--decorate adds the names of branches or tags of the commits that are shown:

```
git log --graph --decorate --oneline
```

**HEAD always refers to the current commit, be it a branch or a specific commit.**

## git tag

Tags are ref's that point to specific points in Git history. Tagging is generally used to capture a point in history that is used for a marked version release (i.e. v1.0.1). A tag is like a branch that doesn’t change. Unlike branches, tags, after being created, have no further history of commits

2 kinds of tag:

- Lightweight tags:

```
git tag <tag_name>
OR
git tag <tag_name>-lw
(<tag_name> is often v1.4)
```

- Annotated tags: store extra meta data such as: the tagger name, email, and date. Best pratice: use annotated tags when you have information.

```
git tag -a v1.4
git tag -a v1.4 -m "my version 1.4" (attach message to tag)
```

To list tag: `git tag`

By default, tags will be attached to HEAD ref. To attach tags to specific commit:

```
git tag -a v1.2 <commit_hash>
```

Replacing old tags:

```
git tag -a -f v1.2 <commit_hash>
```

Pushing tags to remote:

```
git push origin v1.4
```

Checking Out Tags:

```
git checkout v1.4
```

Note: any modification will be stored in a separated branch that you can only refer to using commit hash.

Delete tags:

```
git tag -d v1.4
```

## git blame


https://www.atlassian.com/git/tutorials/inspecting-a-repository/git-blame
