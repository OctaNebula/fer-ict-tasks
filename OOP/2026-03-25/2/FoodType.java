public class FoodType {

    private static int counter = 0;

    private String name;
    private int protein;
    private int carbs;
    private int fat;

    public FoodType(String name, int protein, int carbs, int fat) {
        this.name = name;
        this.protein = protein;
        this.carbs = carbs;
        this.fat = fat;
        counter++;
    }
    public static int getNumberOfCreatedInstances() {
        return counter;
    }

    public int getCarbs() {
        return this.carbs;
    }

    public String getName() {
        return this.name;
    }

    public int getProtein() {
        return this.protein;
    }

    public int getFat() {
        return this.fat;
    }

    public String toString() {
        String result = String.format("%s: p - %d%%, c - %d%%, f - %d%%", this.name, this.protein, this.carbs, this.fat);
        return result;
    }

}
