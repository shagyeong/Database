package ch03;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import assembler.Assembler;
import ch03.ChangePasswordService;
import ch03.DuplicateMemberException;
import ch03.MemberNotFoundException;
import ch03.MemberRegisterService;
import ch03.RegisterRequest;
import ch03.WrongIdPasswordException;

public class MainForAssembler{
    public static void main(String args[]){
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        while(true){
            System.out.println("명령어 입력 : ");
            String command = reader.readLine();
            if(command.equalsIgnoreCase("exit")){
                System.out.println("종료");
                break;
            }
            if(command.startsWith("new ")){
                processNewCommand(command.split(" "));
                continue;
            }
            else if(command.startsWith("change ")){
                processChangeCommand(command.split(" "));
                continue;
            }
        }
        printHelp();
    }
    
    private static Assembler assembler = new Assembler();
    private static void processNewCommand(String[] arg){
        if(arg.length != 5){
            printHelp();
            return;
        }
        MemberRegisterService regsvc = assembler.getMemberRegisterService();
        RegisterRequest req = new RegisterRequest();
        req.setemail(arg[1]);
        req.setname(arg[2]);
        req.setpassword(arg[3]);
        req.setconfirmpassword(arg[4]);
        if(!req.ispasswordequaltoconfirmpasasword()){
            System.out.println("암호가 일치하지 않습니다.\n")
            return;
        }
        try{
            regsvc.regist(req);
            System.out.println("등록했습니다.\n");
        }
        catch(DuplicateMemberException e){
            System.out.println("이미 존재하는 이메일입니다.\n");
        }
    }
    private static void processChangeCommand(String[] arg){
        
    }
    private static void printHelp(){
        //명령 도움말 출력 메서드
    }
}