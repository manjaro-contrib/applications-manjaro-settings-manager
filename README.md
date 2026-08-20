# Manjaro Settings Manager

The Manjaro Settings Manager offers you a series of settings, which are
either enabled by Manjaro (i.e. installation of multiple kernels) or are 
missing from at least some of popular Desktop Environments and Window Managers.

Currently has modules written for Manjaro Hardware Detection (MHWD), Language,
Kernel, Keyboard, Time and Date and User Accounts.

It also includes a daemon to notify user of new language packages or kernels.

Manjaro Settings Manager is under active development.


### BUILD INSTRUCTIONS

```
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr ..
cmake --build .
cmake --install .
```


### DEPENDENCIES

* Qt6 >= 6.4.0
* KF6 >= 6.28
* KF6CoreAddons
* KF6Auth
* KF6ConfigWidgets
* KF6ItemModels
* KF6Notifications
* KF6StatusNotifierItem
* KF6KCMUtils
* KF6IconThemes


### EXECUTION

Now the build is complete and you can run it using `manjaro-settings-manager` command in terminal.

It will also show up the new kcm modules in kde's systemsettings or issuing the command:
`kcmshell6 msm_{kernel,language_packages,mhwd}`


### RESOURCES

* Website        https://manjaro.org/
* Wiki           https://wiki.manjaro.org/
* Mailing List   https://lists.manjaro.org/mailman/listinfo
* Download       https://manjaro.org/get-manjaro/
* IRC            #manjaro (libera.chat)
