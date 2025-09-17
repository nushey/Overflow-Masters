import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        BigInteger numeroGigante = new BigInteger("123456789012345678901234567890");
        
        BigInteger cinco = BigInteger.valueOf(5);
        BigInteger diez = BigInteger.TEN; 

        BigInteger suma = numeroGigante.add(diez);

        BigInteger multiplicacion = cinco.multiply(diez);

        BigInteger potencia = cinco.pow(100);
        int resultadoComparacion = numeroGigante.compareTo(diez);

        if (resultadoComparacion > 0) {
            System.out.println("El número gigante es MAYOR que diez.");
        } else if (resultadoComparacion < 0) {
            System.out.println("El número gigante es MENOR que diez.");
        } else {
            System.out.println("El número gigante es IGUAL a diez.");
        }
        System.out.println("------------------------------------");

        System.out.println("Por favor, introduce un número muy grande:");
        BigInteger a = scanner.nextBigInteger();
        
        scanner.close();
    }
}