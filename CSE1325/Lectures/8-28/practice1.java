public class practice1 // Multiplication Table
{
  public static void main(String[] args)
  {
    System.out.printf("%30sTimes 12 Table\n\n", " ");
    // %30sTimes will add 30 spaces since Java doesn't have a text center

    System.out.printf("     ");
    for(int x = 0; x <= 12; ++x) System.out.printf("%4d ", x);
    // Prints out numbers in column axis, the %4 will move the digit four places

    System.out.printf("\n     ");
    for(int x = 0; x <= 12; ++x) System.out.printf("---- ");
    // Prints out dashes under column numbers

    for(int y = 0; y <= 12; ++y)
      {
        System.out.printf("\n%2d | ", y); // Prints row axis
        for(int x = 0; x <= 12; ++x) // Multiplies row with column
        {
          System.out.printf("%4d ", x*y);
        }
      }
    System.out.printf("\n");
    // No need for a return since function is void
  }
}
