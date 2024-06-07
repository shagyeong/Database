package ch03;

import java.time.LocalDateTime;

public class MemberRegisterService{
    private MemberDao memdao;

    public MemberRegisterService(MemberDao memdao){
        this.memdao = memdao;
    }
    public Long regist(RegisterRequest req){
        Member member = memdao.selectbyemail(req.getemail());
        if(member != null){
            throw new DuplicateMemberException("dup email " + req.getemail());
        }
        Member newmember = new Member(
            req.getemail(),
            req.getpassword(),
            req.getname(),
            LocalDateTime.now()
        );
        memdao.insert(newmember);
        return newmember.getid();
    }
}