package ch03;

public class RegisterRequest{
    private String email;
    private String password;
    private String confirmpassword;
    private String name;

    public String getemail(){return this.email;}
    public void setemail(String email){this.email = email;}
    public String getpassword(){return this.password;}
    public void setpassword(String password){this.password = password;}
    public String getconfirmpassword(){return this.confirmpassword;}
    public void setconfirmpassword(String confirmpassword){this.confirmpassword = confirmpassword;}
    public String getname(){return this.name;}
    public void setname(String name){this.name = name;}

    public boolean ispasswordequaltoconfirmpasasword(){
        return password.equals(confirmpassword);
    }
}