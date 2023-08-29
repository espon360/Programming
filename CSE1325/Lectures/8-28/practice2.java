public class practice2 // Random number generator from 0-1 with Math.random
{
  public static void main(String[] args)
  {
    // use a ternary
    int numberOfRandoms = (args.length > 0) ? Integer.parseInt(args[0]) : 24;
    // Asks if no. of args greater than 0 and if not, parse 24 by default
    double sum = 0;
    double min = 2.0;
    double max = 0.0;
    for(int i = 0; i < numberOfRandoms; ++i)
    {
      double random = Math.random(); // will generate random between 0-1
      if(random < min) min = random;
      if(random > max) max = random;
      sum += random;
      System.out.println(random);
    }
    System.out.println("Statistics:"
                        + "\n Population: " + numberOfRandoms
                        + "\n Minimum: " + min
                        + "\n Maximum: " + max
                        + "\n Average: " + sum / numberOfRandoms);
  }
}
