function getbmivalue() {
    var weight = document.getElementById('weight').value;
    var height = document.getElementById('height').value;

    height = height * 12;
    height = height * 0.025; //Now height is in meter

    var bmi = weight / Math.pow(height, 2);
    bmi = Math.round(bmi);
    document.getElementById('bmivalue').value = bmi;
    
    // checking for invalid inputs
    if(height == "" && weight == "")
        document.getElementById('healthStatus').textContent = "Enter valid Height and Weight";
    else if (height == "" || isNaN(height))
        document.getElementById('healthStatus').textContent = "Enter a valid Height";
    else if (weight == "" || isNaN(weight))
        document.getElementById('healthStatus').textContent = "Enter a valid Weight";
    // if both inputs are valid then calculating bmi
    else {
        if (bmi >= 25) {
            document.getElementById('healthStatus').textContent = "You are overweight!";
        } else if (bmi <= 19) {
            document.getElementById('healthStatus').textContent = "You are underweight!";
        } else {
            document.getElementById('healthStatus').textContent = "Your body is healthy and active!";
        }
    }
}