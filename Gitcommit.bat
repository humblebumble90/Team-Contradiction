@ECHO OFF
echo Press enter to continue without opening
set /p "folder=Which folder are you trying to open?"
cd %folder%
cls
pause
:start
cls
echo you are in %cd%
git branch
echo -----------------------
echo  init - 1
echo  init pull - 2
echo  commit - 3 
echo  force commit - 4
echo  update repository - 5
echo  set global account - 6
echo  pull - 7
echo  create branch - 8
echo  switch branch - 9
echo  push - 10 
echo  merge - 11
echo  reset - 12
echo -----------------------
set /p "set=What do you want to do(input the corrisponding number)?"
if %set%== 1 (goto init)
if %set%== 2 (goto initpull)
if %set%== 3 (goto commit)
if %set%== 4 (goto force)
if %set%== 5 (goto fetch)
if %set%== 6 (goto login)
if %set%== 7 (goto pull)
if %set%== 8 (goto createB)
if %set%== 9 (goto switch)
if %set%== 10 (goto push)
if %set%== 11 (goto merge)
if %set%== 12 (goto reset)
pause
goto end


:reset
echo Resetting the changes from last add
git reset
pause

:merge
echo The highlighted green text is where you are right now
git branch
set /p "merge=Which branch do you want to merge from?"
git merge %merge%
pause
goto start

:switch
git branch
set /p "set=Which branch do you want to switch to?"
git checkout %set%
pause
goto start


:createB
set /p "branch=What would your branch name be?"
git checkout -b %branch%
set /p "pull=Where do you want to pull from?"
git pull origin %pull%
git commit -m "Created a new branch from %pull%"
git push origin %branch%
goto start


:commit
cls
set /p "reason=Enter your reason for this commit:"
git add .
git commit -m "%reason%"
pause
goto push


:push
git branch
set /p "branch=Which branch do you want to push to?"
git push origin %branch%
pause
goto start

:force
cls
echo DO THIS ONLY IF YOU REALLY NEED TO
set /p "reason=Enter your reason for this forced commit:"
git add .
git commit -m "%reason%"
set /p "branch=Which branch do you want to do this to?"
git push -f origin %branch%
pause
goto start

:init
set /p "origin=What is your origin?"
git init
git remote add origin %origin%
git add .
git commit -m "first commit"
git push -u origin master
echo finished setup
pause
goto start

:initpull
set /p "origin=What is your origin?"
git init
git remote add origin %origin%
set /p "branch=What is the branch you want to pull from?"
git pull origin %branch%
echo finished updating local repository
pause 
goto start

:fetch
set /p "branch=What is the branch you want to pull from?"
git pull origin %branch%
echo finished updating local repository
pause
goto start

:end 
cls
set /p "stop=Continue?(y for yes. if yes input anything else)?"
if %stop% == y (goto start) 
exit

:pull
set /p "branch=What branch do you want to pull from?"
git pull origin %branch%
pause
goto start

:login
cls 
set /p "username=What is your username?"
set /p "password=What is your password?"
git config --global user.email "%username%"
git config --global user.password "%password%"
goto start