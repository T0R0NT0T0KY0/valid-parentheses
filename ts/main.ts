function isValid(s: string): boolean {
	const stack = [];
	const bracketsMap = new Map<string, string>([
		[")", "("],
		["}", "{"],
		["]", "["],
	]);

	for (const char of s) {
		if (stack.length !== 0 && bracketsMap.get(char) === stack[stack.length - 1]) {
			stack.pop();
		} else {
			stack.push(char);
		}
	}

	return stack.length === 0;
}

const res1 = isValid("()");
console.log(`test1: ${res1}`);

const res2 = isValid("()[]{}");
console.log(`test2: ${res2}`);

const res3 = isValid("(]");
console.log(`test3: ${res3}`);
