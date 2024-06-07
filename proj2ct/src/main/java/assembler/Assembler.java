package assembler;

import ch03.ChangePasswordService;
import ch03.MemberDao;
import ch03.MemberRegisterService;

public class Assembler{
    private MemberDao memdao;
    private MemberRegisterService regsvc;
    private ChangePasswordService cpwsvc;

    public Assembler(){
        memdao = new MemberDao();
        regsvc = new MemberRegisterService(memdao); //assemble
        cpwsvc = new ChangePasswordService();cpwsvc.setmemberdao(memdao);//assemble
    }
    public MemberDao getMemberDao(){
        return memdao;
    }
    public MemberRegisterService getMemberRegisterService(){
        return regsvc;
    }
    public ChangePasswordService getChangePasswordService(){
        return cpwsvc;
    }
}