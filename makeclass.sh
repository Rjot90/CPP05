#!/usr/bin/env bash

set -euo pipefail

if [ $# -ne 1 ]; then
    echo "Usage: $0 ClassName"
    exit 1
fi

NAME="$1"

# Header file
cat > "${NAME}.hpp" <<EOF
#pragma once

#include <iostream>
#include <string>

class ${NAME} {
public:
    ${NAME}();
    ${NAME}(const ${NAME}& other);
    ${NAME}& operator=(const ${NAME}& other);
    virtual ~${NAME}(); // remove virtual if not needed

    // Methods
};
EOF

# Source file
cat > "${NAME}.cpp" <<EOF
#include "${NAME}.hpp"

${NAME}::${NAME}() {
    std::cout << "${NAME} default constructor called" << std::endl;
}

${NAME}::${NAME}(const ${NAME}& other) {
    std::cout << "${NAME} copy constructor called" << std::endl;
    *this = other;
}

${NAME}& ${NAME}::operator=(const ${NAME}& other) {
    std::cout << "${NAME} assignment operator called" << std::endl;
    if (this != &other) {
        // copy fields/data
    }
    return *this;
}

${NAME}::~${NAME}() {
    std::cout << "${NAME} destructor called" << std::endl;
}
EOF

chmod 0644 "${NAME}.hpp" "${NAME}.cpp"

echo "Created: ${NAME}.hpp and ${NAME}.cpp"
