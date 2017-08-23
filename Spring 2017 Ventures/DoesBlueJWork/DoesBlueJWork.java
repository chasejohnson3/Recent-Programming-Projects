import java.io.*;
public class DoesBlueJWork
{
    
    
    static String letterGrade(double gradePercentage)
    {
        if (gradePercentage >= 97)
        {
            return "A+";
        }
        else if (gradePercentage >= 93)
        {
            return "A";
        }
        else if (gradePercentage >= 90)
        {
            return "A-";
        }
        else if (gradePercentage >= 87)
        {
            return "B+";
        }
        else if (gradePercentage >= 83)
        {
            return "B";
        }
        else if (gradePercentage >= 80)
        {
            return "B-";
        }
        else if (gradePercentage >= 77)
        {
            return "C+";
        }
        else if (gradePercentage >= 73)
        {
            return "C";
        }
        else if (gradePercentage >= 70)
        {
            return "C-";
        }
        else if (gradePercentage >= 60)
        {
            return "D";
        }
        else
        {
            return "F";
        }

    }

    public static void main(String [] args)
    {
        String each_line[];
        int id;
        double attendance, average, hw1, hw2, hw3, hw4, hw5, hw6, hw7, exam1, exam2, finalExam, courseGradePercentage;          
        String fileNameInput = "sampleGrades.txt";
        String fileNameOutput = "sampleGradeData.txt";
        String line = null;
        finalExam = 0;
        

        //fileWriter.write("Test");
        try 
        {
            FileReader fileReader = new FileReader(fileNameInput);
            BufferedReader bufferedReader = new BufferedReader(fileReader);

            PrintWriter printWriter = new PrintWriter(fileNameOutput);
                
            
            
            
            line = bufferedReader.readLine(); // get rid of first line.
            String[] lineArray = line.split(" ");

            

            for (int i=0; i< lineArray.length; i++)
            {
                 System.out.print(lineArray[i]);
                
                 //printWriter.print(lineArray[i]);
            }
            System.out.println();
            printWriter.println("ID     Course_Percentage    Letter_Grade");
            while((line = bufferedReader.readLine()) != null)
            {
                lineArray = line.split(" ");
                

                
                for (int i=0; i< lineArray.length; i++)
                {
                    lineArray[i] = lineArray[i].replace(" ", "");
                    lineArray[i] = lineArray[i].replace("\t", "");
                    System.out.print(lineArray[i] + " ");
                    if (i==11)
                    {
                        finalExam = Float.parseFloat(lineArray[i]);
                    }
                }
                
                
                id = Integer.parseInt(lineArray[0]);
                attendance = Double.parseDouble(lineArray[1]);
                hw1 = Double.parseDouble(lineArray[2]);
                hw2 = Double.parseDouble(lineArray[3]);
                hw3 = Double.parseDouble(lineArray[4]);
                hw4 = Double.parseDouble(lineArray[5]);
                hw5 = Double.parseDouble(lineArray[6]);
                hw6 = Double.parseDouble(lineArray[7]);
                hw7 = Double.parseDouble(lineArray[8]);
                exam1 = Double.parseDouble(lineArray[9]);
                exam2 = Double.parseDouble(lineArray[10]);
                
                System.out.println();
                System.out.println("ID: " + id);
                System.out.println("Attendance: " + attendance);
                System.out.println("HW1: " + hw1);
                System.out.println("HW2: " + hw2);
                System.out.println("HW3: " + hw3);
                System.out.println("HW4: " + hw4);
                System.out.println("HW5: " + hw5);
                System.out.println("HW6: " + hw6);
                System.out.println("HW7: " + hw7);
                System.out.println("Exam1: " + exam1);
                System.out.println("Exam2: " + exam2);
                System.out.println("Final: " + finalExam);
                
                
                
                
                
                
                
                System.out.println();
                System.out.println(lineArray.length);
                courseGradePercentage = (attendance*.1/25.0 + (hw1 + hw2 + hw3 + hw4 +
                hw5 + hw6 + hw7)*.35/700 + exam1*.15/25 + exam2*.15/25 + finalExam *
                .25/40)*100;
                
                System.out.println("The grade percentage is " + courseGradePercentage);
                //courseGradePercentage.setPrecision(4);
                
                printWriter.print(id);
                //printWriter.print("    " + courseGradePercentage);
                printWriter.print("    " + courseGradePercentage);
                printWriter.print("    " + letterGrade(courseGradePercentage));
                System.out.println();
                printWriter.println();
            }
        
            bufferedReader.close();
            printWriter.close();
        }
        catch(FileNotFoundException ex)
        {
            System.out.println("Unable to open file '" + fileNameInput + "'");
        }
        catch(IOException ex)
        {
            System.out.println("Error reading file '" + fileNameInput + "'");
        }
    }
}

