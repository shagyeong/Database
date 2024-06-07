package ch03;

import java.util.HashMap;
import java.util.Map;

public class MemberDao{
    private static long nextid = 0;
    private Map<String, Member> map = new HashMap<>();

    public Member selectbyemail(String email){
        return map.get(email);
    }
    public void insert(Member member){
        member.setid(++nextid);
        map.put(member.getemail(), member);
    }
    public void update(Member member){
        map.put(member.getemail(), member);
    }
}