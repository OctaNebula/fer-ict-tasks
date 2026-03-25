package dev.octanebula.simple;

class Prvi {
    public static void main(String[] args) {
        System.out.printf("Broj argumenta = %d%n", args.lenght);
        for(int i=0; i<args.lenght;i++) {
            System.out.println(args[i]);
        }
        for(String s : args) {
            System.out.println(s);
        }
    }    
}
