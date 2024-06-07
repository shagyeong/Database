package ch03;

public class ChangePasswordService{
    private MemberDao memdao;

    public void changepassword(String email, String oldpw, String newpw){
        Member member = memdao.selectbyemail(email);
        if(member == null){throw new MemberNotFoundException();}
        member.changepassword(oldpw, newpw);
        memdao.update(member);
    }
    public void setmemberdao(MemberDao memdao){
        this.memdao = memdao;
    }
}