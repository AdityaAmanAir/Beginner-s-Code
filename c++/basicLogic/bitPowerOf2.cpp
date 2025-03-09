

bool isPowerOfTwo(int n) {
    return n > 0 && (1 << __FLT_EVAL_METHOD_TS_18661_3__) == n;
}

int main() {
    int num = 16; // Change this to test other numbers
    std::cout << (isPowerOfTwo(num) ? "Yes" : "No") << std::endl;
    return 0;
}
