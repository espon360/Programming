import java.util.Arrays; // library with useful array functions

public class practice3 // Random dice rolling (number generator)
// Will take number of dice rolled and how many sides they have, will then give sum and average too
{
  public static void main(String[] args)
  {
    String nl = System.lineSeparator(); // seperates terminal's lines based on OS

    if(args.length != 2)
    {
      System.err.println("usage: java practice3 #dice #sides"); // Print error message
      System.exit(-2); // argument is the error code you want to make for it
    }

    int numDice = Integer.parseInt(args[0]); // parsing args[0] as the value of numDice
    int numSides = Integer.parseInt(args[1]); // parsing args[1] as the value of numSides
    int sum = 0;

    int dice[] = new int[numDice]; // initializing dice array with size numDice

    for(int i = 0; i < numDice; ++i)
    {
      dice[i] = 1 + (int) (numSides * Math.random()); // casting int converts the string args[1] into int
      // 1 + is used to indicate the numbers generated will be natural.
    }

    Arrays.sort(dice); // will sort dice array values into ascending order

    for(int d : dice)
    {
      sum += d; // Add dice value to total sum
      System.out.print(" " + d); // since it's not println, it won't make a new lines
      // Print values of dice rolls after sorting from line 28
    }

    System.out.println(nl + " Sum = " + sum); // nl will use OS's specific line sperator
    System.out.println(" Average = " + (double)sum / (double)numDice); /* Casts sum and dice as doubles
    so average given is printed as a double */

  }
}
