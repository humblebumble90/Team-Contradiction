@ECHO OFF
echo Press enter to continue without opening
set /p "folder=Which folder are you trying to open?"
cd %folder%
cls
echo MAKE SURE YOU PULL BEFORE YOU COMMIT SO YOU DONT NEED TO FORCE COMMIT
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
echo  push -10 
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
pause
goto end

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
goto end


:commit
cls
set /p "reason=Enter your reason for this commit:"
git add .
git commit -m "%reason%"
pause
goto end


:push
set /p "Which branch do you want to push to?"
git push origin %branch%
pause
goto end

:force
cls
set /p "reason=Enter your reason for this forced commit:"
git add .
git commit -m "%reason%"
git push -f origin master
pause
goto end

:init
set /p "origin=What is your origin?"
git init
git remote add origin %origin%
git add .
git commit -m "first commit"
git push -u origin master
echo finished setup
pause
goto end

:initpull
set /p "origin=What is your origin?"
git init
git remote add origin %origin%
git pull origin master
echo finished updating local repository
pause 
goto end

:fetch
git pull origin master
echo finished updating local repository
pause
goto end

:end 
cls
set /p "stop=Continue?(y for yes. if yes input anything else)?"
if %stop% == y (goto start) 
exit

:pull
git pull origin master
pause
goto end

:login
cls 
set /p "username=What is your username?"
set /p "password=What is your password?"
git config --global user.email "%username%"
git config --global user.password "%password%"
goto end