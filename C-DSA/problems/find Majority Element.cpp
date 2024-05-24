int majorityElement(int a[], int size) {
    int candidate = -1;
    int count = 0;

    // Candidate dhundhne ka loop
    for (int i = 0; i < size; i++) {
        if (count == 0) {
            candidate = a[i];
            count = 1;
        } else if (a[i] == candidate) {
            count++;
        } else {
            count--;
        }
    }

    // Candidate ko verify karne ka loop
    count = 0;
    for (int i = 0; i < size; i++) {
        if (a[i] == candidate) {
            count++;
        }
    }

    if (count > size / 2) {
        return candidate;
    } else {
        return -1; // Majority element nahi mila
    }
}
