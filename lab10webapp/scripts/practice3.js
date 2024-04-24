function validate() {
    let pass1 = document.getElementById("pass1").value;
    let pass2 = document.getElementById("pass2").value;


    if (pass1.length < 8) {
        alert("The length of the first password is less than 8 characters")
    } else if (pass2.length < 8) {
        alert("The length of the second password is less than 8 characters")
    } else if (pass1 != pass2) {
        alert("The passwords don't match!")
    } else {
        alert("The passwords match and are at least 8 characters long! Great work.")
    }
}
