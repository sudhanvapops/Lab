public class Student {

    private String usn,name,branch;
    private int semister;

    public int getSemister() {
        return semister;
    }
    
    public String getUsn() {
        return usn;
    }
    public String getName() {
        return name;
    }
    public String getBranch() {
        return branch;
    }

    public Student(String usn,String name, String branch, int semister){
        this.branch = branch;
        this.usn = usn;
        this.semister = semister;
        this.name = name;
    }

    public void studentStatus(){
        System.out.println("Name: "+this.getName());
        System.out.println("USN: "+this.getUsn());
        System.out.println("Branch: "+this.getBranch());
        System.out.println("Semister: "+this.getSemister());
    }


    public static void main(String[] args) {
        
        Student su = new Student("4VM23IS048", "Sudhanva S", "ISE", 3);

        su.studentStatus();
    }


}
