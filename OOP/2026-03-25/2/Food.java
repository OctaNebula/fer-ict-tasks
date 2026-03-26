public class Food {
    private FoodType type;
    private int weight;
    
    public Food(FoodType type, int weight) {
        this.weight = weight;
        this.type = type;
    }

    public FoodType getType() {
        return type;
    }

    public int getWeight() {
        return weight;
    }

    public String toString() {
        String result = type.toString() + String.format(", w - %dg", weight);
        return result;
    }

    public double getProtein() {
        double result = (double) (weight * type.getProtein() / 100.0);
        return result;
    }

    public double getCarbs() {
        double result = (double) (weight * type.getCarbs() / 100.0);
        return result;
    }

    public double getFat() {
        double result = (double) (weight * type.getFat() / 100.0);
        return result;
    }

    public String toStringInGrams() {
        String result = String.format("%s: p - %.1fg, c - %.1fg, f - %.1fg, w - %dg", type.getName(), getProtein(), getCarbs(), getFat(), weight);
        return result;
    }

    
}
