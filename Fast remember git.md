Fast remember git

Download
git clone [url]

Let's create new branch
git branch [branch]
git checkout [branch]

Make changes in files

Check list of changed files
git status

Check what changed in files for unstaged (not ready for commit)
git diff

Check what changed in files for staged (ready for commit)
git diff --staged

Add file for commit
git add [file]

Remove file for commit
git reset [file]

Remove file from repo
git rm [file]

Make a commit
git commit -m "Message"

Send all new commits to remote repo to master branch
git push origin

Send all new commits to remote repo to branch
git push origin [branch]

Get and merge commits from remote
git pull

Get commits from remote, but not merge them
git fetch origin

Merge remote branch
git merge origin/[branch]

Show commit history
git log
git log --oneline

Apply commits of branch ahead of master
git rebase master