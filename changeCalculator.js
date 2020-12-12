let money = {
	two: 0,
	five: 0,
	ten: 0,
};

function change(cash) {
	if (cash < 2 || cash === 3) {
		return false;
	}

	if ((cash % 2) === 0) {
		money.two = Math.floor(cash / 2);
		money.ten = Math.floor(money.two / 5);
		money.two -= (5 * money.ten);
    }
	else {
		money.five = 1;
		cash -= 5;
		money.two = Math.floor(cash / 2);
		money.ten = Math.floor(money.two / 5);
		money.two -= (5 * money.ten);
	}
	return money;
}

console.log(change(11));
