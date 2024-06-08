# 3장 스프링 DI
## 3.1 의존이란 무엇인가?
### DI
#### DI(dipendency injection)
* **DI** : 의존 주입
* 2장의 의존 : 프로젝트 컴파일 실행시 사용할 아티팩트를 클래스패스에 추가하는 것
* 3장의 의존 : 객체 간의 의존
#### 예제 : MemberRegisterService.java
```java
import java.time.LocalDateTime;

public class MemberRegisterService{
    private MemberdDao memdao = new MemberDao();
    
    public void regist(RegisterRequest req){
        Member mem = mdemao.selectByEmail(req.getEmail());
        if(member != NULL){
            throw new DuplicateMemberException("dup email " + req.getEmail());
        }
        Member newmem = new Member(
            req.getEmail(),
            req.getPassword(),
            req.getName(),
            LocalDateTime.now()
        );
        memdao.insert(newmem);
    }
}
```
* DAO(data access object) : DB상 데이터 접근을 위한 객체
* exception(예외) 발생 : 같은 이메일을 가진 회원이 존재할 경우 throw
* **의존** : 어떤 클래스가 다른 클래스의 메서드를 이용하는 관계
    * **'MemberRegisterService가 MemberDao에 의존한다.'**
    * MemberDao의 메서드명을 변경하면 MemberRegisterService의 소스 코드도 **같이 변경됨**
#### 객체 지향 관점에서의 객체 주입
* 예제 MemberRegisterService.java에서 **클래스 내부에서 의존 객체를 생성**하였음
* 유지보수/객체 지향 관점 측면에서 볼 때 문제점이 될 수 있음
* **스프링과 관련된 의존 객체 생성 : DI**

## 3.2 DI를 통한 의존 처리
### DI(dipendency injection)
* DI(의존 주입) : 의존하는 객체를 (클래스 내부에서) 직접 생성하지 않고 **의존 객체를 전달받는** 방식
#### 예제 : MemberRegisterService.java
```java
...
public MemberRegisterService(MemberDao memdao){
    this.memdao = memdao;
}
...
```
* 의존 객체를 직접 생성하지 않고 생성자를 통해 전달(주입)받음

## 3.3 DI와 의존 객체 변경의 유연함
### 예제 : 의존 객체를 직접 생성하는 방식
#### ChangePasswordService.java
```java
public class ChangePasswordService{
    private MemberDao memdao = new MemberDao();
    ...
}
```
#### CachedMemberDao.java
```java
public class CachedMemberDao{
    ...
}
```
#### CachedMembderDao 사용하기
* MemberDao를 **의존하는 클래스 내부의 소스 코드를 모두 수정해야 함**
```java
public class MemberRegisterService{
    private MembderDao memdao = new MemberDao();
    ...
}

public class ChangePasswordService{
    private MembderDao memdao = new MemberDao();
    ...
}

...
```
```java
public class MemberRegisterService{
    private MembderDao memdao = new CachedMemberDao();
    ...
}

public class ChangePasswordService{
    private MembderDao memdao = new CachedMemberDao();
    ...
}
...
```
### 예제 : 객체 주입 방식
#### MemberRegisterService.java
```java
public class MemberRegisterService{
    private MembderDao memdao;
    public MemberRegisterService(MemberDao memdao){
        this.memdao = memdao;
    }
    ...
}
```
#### ChangePasswordService.java
```java
public class ChangePasswordService{
    private MembderDao memdao;
    public ChangePasswordService(MemberDao memdao){
        this.memdao = memdao;
    }
    ...
}
```
#### CachedMemberDao 사용하기
* **MemberDao 객체를 생성하는 코드만 변경하면 됨**
```java
MemberDao memdao = new MemberDao();
MemberregisterService regsvc = new MemberregisterService(memdao);
ChangepasswordService pwdsvc = new ChangepasswordService(memdao);
```
```java
MemberDao memdao = new CachedMemberDao();
MemberregisterService regsvc = new MemberregisterService(memdao);
ChangepasswordService pwdsvc = new ChangepasswordService(memdao);
```

## 3.4 예제 프로젝트 만들기
### 개요
#### 예제 코드 명시
* 코드가 정상적으로 작동하는 것을 확인한 후 옮겨붙이기
#### 파일 트리
* src/main
    * assembler
        * Assembler.java
    * java/ch03
        * Member.java
            * id
            * email
            * password
            * name
            * registerdatetime
            * getter/setter
            * changepassword(String oldpw, String newpw)
        * WrongIdPasswordException.java
            * extends RuntimeException
        * MemberDao.java
            * nextid
            * map
            * selectbyemail(String email)
            * insert(Member member)
            * update(Member member)
        * RegisterRequest.java
            * email
            * password
            * confirmpassword
            * name
            * getter/setter
            * ispasswordequaltoconfirmpassword()
        * DuplicateMemberException.java
            * extends RuntimeException
        * ChangePasswordService.java
            * memdao
            * setter
            * changepassword(String email, String oldpw, String newpw)
        * MemberNotFoundException.java
### 3.4.1 회원 데이터 관련 클래스
#### Member.java
```java
```

#### WrongIdPasswordException.java
```java
```
#### MemberDao.java
```java
```
### 3.4.2 회원 가입 처리 관련 클래스
#### RegisterRequest.java
```java
```
#### DuplicateMemberException.java
```java
```
### 3.4.3 암호 변경 관련 클래스
#### ChangePasswordService.java
```java
```
#### MemberNotFoundException.java
```java
```

## 3.5 객체 조립기
### 개요
#### 조립기(assembler)
* **객체 조립기** : (main 메서드에서 생성/주입하지 않고) 객체를 생성/주입하는 클래스를 따로 작성하는 방식
#### Assembler.java
```java
```
#### 조립기 사용 예제
```java
...
Assembler assembler = new Assembler()
ChangePasswordService cpwsvc = assembler.getchangepasswordservice();
cpwsvc.changepassword("shagyeong@noj.am", "1234", "2222");
...
```
* assembler.getchangepasswordservice() : 조립기에서 생성한 객체이므로 **memberdao 객체가 주입되어 있음**
### 3.5.1 조립기 사용 예제
#### mainforassembler.java
```java

```

## 3.6 스프링의 DI 설정
### 3.6.1 스프링을 이용한 객체 조립과 사용
### 3.6.2 DI 방식 1 : 생성자 방식
### 3.6.3 DI qkdtlr 2 : 세터 메서드 방식
### 3.6.4 기본 데이터 타입 값 설정

## 3.7 @Configuration 설정 클래스의 @Bean 설정과 싱글톤

## 3.8 두 개 이상의 설정 파일 사용하기
### 3.8.1 @Configuration 애노테이션, 빈, @Autowired 애노테이션
### 3.8.2 @Import 애노테이션 사용

## 3.9 getBean() 메서드 사용

## 3.10 주입 대상 객체를 모두 빈 객체로 설정해야 하는가?
