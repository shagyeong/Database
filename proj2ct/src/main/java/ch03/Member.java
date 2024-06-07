package ch03;
import java.time.LocalDateTime;

public class Member{
    private Long id;
    private String email;
    private String password;
    private String name;
    private LocalDateTime registerdatetime;
    
    public Member(
        String email,
        String password,
        String name,
        LocalDateTime registerdatetime
    ){
        this.email = email;
        this.password = password;
        this.name = name;
        this.registerdatetime = registerdatetime;
    }
    public Long getid(){return this.id;}
    public void setid(Long id){this.id = id;}
    public String getemail(){return this.email;}
    public void setemail(String email){this.email = email;}
    public String getpassword(){return this.password;}
    public void setpassword(String password){this.password = password;}
    public String getname(){return this.name;}
    public void setname(String name){this.name = name;}
    public LocalDateTime getregisterdatetime(){return this.registerdatetime;}
    public void setregisterdatetime(LocalDateTime registerdatetime){this.registerdatetime = registerdatetime;}

    public void changepassword(String oldpw, String newpw){
        if(!password.equals(oldpw)){throw new WrongIdPasswordException();}
        this.password = newpw;
    }
}


















