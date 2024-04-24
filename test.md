### JDK, MAVEN 설치
```
$ sudo apt-get update
$ sudo apt-get install openjdk-8-jdk
$ sudo apt-get install maven
$ java -version
openjdk version "1.8.0_xxx"
...
$readlink -f $(which java)
/usr/lib/jvm/java-8-openjdk-amd64/jre/bin/java
```
```
#etc/profile
...
export JAVA_HOME=/usr/lib/jvm/java-8-openjdk-amd64
export PATH=$PATH:$JAVA_HOME_bin
export MVN_HOME=/usr/share/maven
export PATH=$PATH:$MVN_HOME/bin
```
```
$ source /etc/profile
$ echo $JAVA_HOME
/usr/lib/jvm/java-8-openjdk-amd64
$ echo $PATH|grep java
.../usr/lib/jvm/java-8-openjdk-amd64/bin
```
### 그레이들 설치
```
$ wget https://services.gradle.org/distributions/gradle-7.5.1-bin.zip -p /tmp
$ sudo unzip -d /opt/gradle gradle-7.5.1-bin.zip
$ ls /opt/gradle/gradle-7.5.1
LICENSE  NOTICE  README  bin  init.d  libs
```
```
#etc/profile
...
export GRADLE_HOME=/opt/gradle/gradle-7.5.1
export PATH=$PATH:$GRADLE_HOME/bin
```
```
$ source /etc/profile
$ echo GRADLE_HOME
GRADLE_HOME
```