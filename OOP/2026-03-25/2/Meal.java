public class Meal {
    private Food[] ingredients;

    public Meal(Food... ingredients) {
        this.ingredients = ingredients;
    }

    public void printIngredients() {
        for (int i = 0; i < ingredients.length; i++) {
            System.out.printf("Ingredient[%d] = %s\n", i, ingredients[i].toStringInGrams());
        }
    }

    public int getNumberOfIngredients() {
        return ingredients.length;
    }

    public Food getIngredient(int index) {
        if (index < 0) {
            return null;
        }
        if (index >= ingredients.length) {
            return null;
        }
        return ingredients[index];
    }

    public Meal(Meal originalMeal, int newTotalWeight) {
        int originalWeight = 0;
        for (int i = 0; i < originalMeal.ingredients.length; i++) {
            originalWeight += originalMeal.ingredients[i].getWeight();
        }

        this.ingredients = new Food[originalMeal.ingredients.length];

        for (int i = 0; i < ingredients.length; i++) {
            Food originalFood = originalMeal.ingredients[i];
            int newScaledWeight = (int) (originalFood.getWeight() * ((double) newTotalWeight / originalWeight));
            this.ingredients[i] = new Food(originalFood.getType(), newScaledWeight);
        }
    }

    public double compare(Meal otherMeal) {
        int thisTotalWeight = 0;
        for (int i = 0; i < this.ingredients.length; i++) {
            thisTotalWeight += this.ingredients[i].getWeight();
        }
        int otherTotalWeight = 0;
        for (int i = 0; i < otherMeal.ingredients.length; i++) {
            otherTotalWeight += otherMeal.ingredients[i].getWeight();
        }

        double totalSimilarity = 0.0;

        for (int i = 0; i < this.ingredients.length; i++) {
            for (int j = 0; j < otherMeal.ingredients.length; j++) {
                if (this.ingredients[i].getType().getName().equals(otherMeal.ingredients[j].getType().getName())) {
                    double pct1 = (this.ingredients[i].getWeight() / (double) thisTotalWeight * 100.0);     
                    double pct2 = (otherMeal.ingredients[j].getWeight() / (double) otherTotalWeight * 100.0);
                    totalSimilarity += Math.min(pct1, pct2);           
                }

            }
        }

        return totalSimilarity;
    }
}
