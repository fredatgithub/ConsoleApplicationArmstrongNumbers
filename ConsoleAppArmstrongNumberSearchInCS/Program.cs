using System;

namespace ConsoleAppArmstrongNumberSearchInCS
{
  internal class Program
  {
    static void Main()
    {
      // Les nombres Armstrong sont des nombres qui sont égaux à la somme de leurs chiffres élevés à la puissance du nombre de chiffres. Par exemple, 153 est un nombre Armstrong car 1^3 + 5^3 + 3^3 = 153.
      // Les premiers nombres Armstrong sont : 1, 153, 370, 371, 407
      // entre 1_000 et 9_000, les nombres Armstrong sont : 1634, 8208, 9474
      // entre 10_000 et 50_000, les nombres Armstrong sont : aucun
      // entre 50_000 et 100_000, les nombres Armstrong sont : 54 748, 92 727, 93 084
      // entre 100_000 et 500_000, les nombres Armstrong sont : aucun
      // entre 500_000 et 1_000_000, les nombres Armstrong sont : 548_834
      // entre 1_000_000 et 10_000_000, les nombres Armstrong sont : 1 741 725, 4 210 818, 9 800 817, 9 926 315
      // entre 10_000_000 et 100_000_000, les nombres Armstrong sont : 24 678 050, 24 678 051, 88 593 477
      // entre 100_000_000 et 1_000_000_000, les nombres Armstrong sont : 146 511 208, 472 335 975, 534 494 836, 912 985 153

      Action<string> display = Console.WriteLine;
      const int startNumber = 100_000_000;
      const int endNumber = 1_000_000_000;
      var listOfNumbers = new System.Collections.Generic.List<int>();

      display($"Calcul des nombres Armstrong entre {startNumber} et {endNumber} :");
      for (int i = startNumber; i <= endNumber; i++)
      {
        int numberOfDigits = i.ToString().Length;
        int[] digits = new int[numberOfDigits];
        digits = FillArray(i);
        int sumOfPowers = ComputeSumOfPowers(i, digits);
        if (sumOfPowers == i)
        {
          display($"{i} est un nombre Armstrong");
          listOfNumbers.Add(i);
        }
      }

      display("Fin du calcul.");

      // display the list of Armstrong numbers found if any
      if (listOfNumbers.Count == 0)
      {
        display($"Aucun nombre Armstrong trouvé dans la plage spécifiée ({startNumber} à {endNumber}).");
      }
      else
      {
        display("Liste des nombres Armstrong trouvés :");
        display(string.Join(", ", listOfNumbers));
      }

      display("Appuyez sur une touche pour quitter...");
      Console.ReadKey();
    }

    private static int[] FillArray(int number)
    {
      int[] digits = new int[number.ToString().Length];
      for (int j = 0; j < digits.Length; j++)
      {
        digits[j] = int.Parse(number.ToString()[j].ToString());
      }

      return digits;
    }

    private static int ComputeSumOfPowers(int number, int[] digits)
    {
      int result = 0;
      int numberOfDigits = digits.Length;
      for (int j = 0; j < digits.Length; j++)
      {
        result += (int)Math.Pow(digits[j], numberOfDigits);
      }

      return result;
    }
  }
}
