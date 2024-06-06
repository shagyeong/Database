# 2장 스프링 시작하기
## 2.1 스프링 프로젝트 시작하기
### 2.1.1 프로젝트 폴더 생성

### 2.1.2 메이븐 프로젝트 생성
#### pom.xml
* pom.xml : 프로젝트에 대한 설정 정보를 관리하는 파일
* 의존 모듈, 플러그인 등에 대한 설정
* 모든 메이븐 프로젝트는 프로젝트의 루트 폴더에 pom.xml 파일을 가짐
#### 프로젝트 식별자 지정
```xml
<!--pom.xml-->
<artifactId>proj2ct</artifactId> 
```
#### 자바 버전, 인코딩 지정
```xml
<!--pom.xml-->
<plugin>
	<artifactId>maven-compiler-plugin</artifactId>
	<version>3.7.0</version>
	<configuration>
		<source>1.8</source>
		<target>1.8</target>
		<encoding>utf-8</encoding>
	</configuration>
</plugin>
```
#### 메이븐 의존 설정
```xml
<!--pom.xml-->
<dependencies>
	<dependency>
		<groupId>org.springframework</groupId>
		<artifactId>spring-context</artifactId>
		<version>5.0.2.RELEASE</version>
	</dependency>
</dependencies>
```
* **의존(dependency)** 추가 : 프로젝트의 소스 코드를 컴파일하고 실행할 때 사용할 클래스패스에 **아티팩트**를 추가하는 것
* **아티팩트(artifact)** : 메이븐의 모듈 단위
* 각 아티팩트의 완전한 이름 : '아티팩트명-버전.jar'
* 위 코드는 spring-context-5.0.2.RELEASE.jar에 대한 의존성을 추가함
#### 의존 아티팩트는 어디에 있는가?
* 메이븐 **로컬 레포지토리**(그룹ID\아티팩트ID\버전 폴더)에 아티팩트ID-버전.jar 형식의 파일이 있는지 검사하여 존재하면 해당 파일을 이용한다.
* 로컬 레포지토리에 없는 경우 **메이븐 원격 중앙 레포지토리**로부터 해당 파일을 다운로드해 로컬에 복사한 뒤 그 파일을 사용
* 메이븐 기본 로컬 레포지토리 : 사용자홈폴더\.m2\repository
* 메이븐 원격 레포지토리 : Apache 재단에서 관리함 - 오픈 소스 프로젝트에서 중앙 레포지토리에 파이 등록 가능
#### 의존 전이(transitive dependencies)
* **의존 전이** : 의존 아티팩트가 의존하는 아티팩트 또한 의존 대상으로 포함하는 것
* 예시
* spring-context
    * spring-core -> spring-jcl
    * spring-beans
    * spring-aop
    * aspectjweaver
#### 메이븐 기본 폴더 구조
* src\main\java : 메이븐에 정의되어 있는 기본 폴더 구조 - 자바 소스 코드가 위치함
* src\maini\resources : 다른 자원 파일(XML, 프로퍼티 파일 등)이 필요할 경우
#### 메이븐 프로젝트 임포트
### 2.1.3 그레이들 프로젝트 생성
### 2.1.4 예제 코드 작성
#### Greeter.java
```java
package ch02;

public class Greeter {
    private String format;

    public String greet(String guest){
        return String.format(format, guest);
    }

    public void setFormat(String format){
        this.format = format;
    }
}
```
#### AppContext.java
```java
package ch02;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

@Configuration //해당 클래스를 스프링 설정 클래스로 지정
public class AppContext {
	@Bean
	public Greeter greeter() {
		Greeter g = new Greeter();
		g.setFormat("%s, 안녕하세요!");
		return g;
	}
}
```
* **빈(bean) 객체** : 스프링이 생성하는 객체
* Bean 애노테이션 : 해당 메서드가 생성한 객체가 스프링이 관리하는 빈 객체로 등록됨
* Bean 애노테이션 객체는 생성 후 알맞게 초기화해야 함(g.setFormat())
#### Main.java
```java
package ch02;

import org.springframework.context.annotation.AnnotationConfigApplicationContext;

public class Main2 {

	public static void main(String[] args) {
		AnnotationConfigApplicationContext ctx = 
				new AnnotationConfigApplicationContext(AppContext.class);
		Greeter g = ctx.getBean("greeter", Greeter.class);
		String msg = g.greet("스프링");
		System.out.println(msg);
		ctx.close();
	}
}
```
* AnnotationConfigApplicationContext : 자바 설정에서 정보를 읽어와 빈 객체를 생성하고 관리함
* AnnotationConfigApplicationContext 객체 생성시 AppContext 클래스를 생성자 매개변수로 전달, AnnotationConfigApplicationContext는 AppContext에 정의된 @Bean 설정 정보를 읽어와 Greeter 객체를 생성하고 초기화
* getBean() : AnnotationConfigApplicationContext가 Bean 객체를 검색할 때 사용
* "greeter" : 빈 객체의 이름
* Greeter.class : 빈 객체의 타입

## 2.2 객체 컨테이너
### 개요
#### 개요
* 예제 프로그램의 핵심 : Annotation, AnnotationConfigApplicationContext
* 스프링의 핵심 기능 : 객체 생성/초기화
* AppicationContext 인터페이스 : 객체 생성/초기화와 관련된 인터페이스
* AnnotationConfigApplicationContext : Application Context 인터페이스를 구현한 클래스 - 자바 클래스에서 정보를 읽어와 객체 생성과 초기화 수행
#### 메이븐 의존 그래프
* BeanFactory
    * 객체 생성과 검색에 대한 기능 정의
    * getBean()이 정의되어 있음
    * 싱글톤/프로토타입 빈 확인
* ApplicationContext
    * 메시지, 프로필/환경 변수 처리 기능 추가 정의
* AnnotationConfigApplicationContext
    * 자바 에노테이션을 이용한 클래스로부터 객체 생성 정보를 가져옴
* GenericXmlApplicationContext
    * XML로부터 객체 설정 정보를 가져옴
* GenericGroovyApplicationContext
    * 그루비 코드를 이용해 설정 정보를 가져옴
* **컨테이너(container)** : 빈 객체의 생성/초기화/보관/제거 등을 관리하는 ApplicationContext, BeanFactory 등을 '스프링 컨테이너'라고 표현함
### 2.2.1 싱글톤(singleton) 객체
#### Main2.java
```java
package ch02;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;

public class Main{
    public static void main(String[] args){
        AnnotationConfigApplicationContext ctx = new AnnotationConfigApplicationContext(AppContext.class);
        greeter g1 = ctx.getBean("greeter, Greeter.class);
        greeter g2 = ctx.getBean("greeter, Greeter.class);
        System.out.println("(g1 == g2) = " + (g1 == g2));
        ctx.close();
    }
}
```
```
(g1 == g2) = true
```
* g1과 g2가 같은 객체임을 의미
* **싱글톤 객체** : 별도 설정을 하지 않을 경우 스프링은 한 개의 빈 객체만을 생성 - '싱글톤 범위를 갖는다'라고 표현
* 예제 : 2개의 객체 생성
```java
@Bean
public Greeter greeter(){
    Greeter g = new Greeter();
    g.setFormat("%s, 안녕하세요!");
    return g;
}
```
```java
@Bean
public Greeter greeter2(){
    Greeter g = new Greeter();
    g.setFormat("안녕하세요!, %님!");
    return g;
}
```
#### 프로토타입 범위
* 6장에서 설명