public class Employee {

    private int id;
    private String name;
    private double salary;

    public int getId(){
        return id;
    }

    public double getSalary(){
        return salary;
    }

    public String getName(){
        return name;
    }

    public Employee(int id, String name, double salary){
        this.id = id;
        this.name = name;
        this.salary = salary;
    }

    public void raiseSalary(double percentage){

        if (percentage < 0){
            System.out.println("\nInvalid Percentage, Salary remained unchanged");
            return;
        }

        double raiseSalary = salary * (percentage / 100);
        salary += raiseSalary;
        System.out.println("\nSalary Raised By: "+percentage+"%"+"\nNew Salary: "+salary+"\n");
    }

    public void employeeStatus(){
        System.out.println("ID: "+this.getId());
        System.out.println("Name: "+this.getName());
        System.out.println("Salary: "+this.getSalary());
    }

    public static void main(String[] args){

        Employee emp = new Employee(101, "Sudhanva S", 50000.0);
        System.out.println("Employee Status: ");
        emp.employeeStatus();
        
        emp.raiseSalary(10);
        
        System.out.println("\nUpdated Employee Status:");
        emp.employeeStatus();

        emp.raiseSalary(-20);

    }

}