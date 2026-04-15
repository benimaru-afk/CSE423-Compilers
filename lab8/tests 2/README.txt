This test folder was built by splitting a full coverage file into smaller focused tests.

Distributed from the full coverage file:
- tests/k0/: variables, literals, functions, if/else, while, break/continue, when
- tests/kotlin/: imports, expression-body function, named arguments, nullable types, Elvis, safe call, cast, const val, ranges
- tests/errors/: lexical, syntax, and semantic failures

Folders:
- tests/k0     => legal k0-style programs
- tests/kotlin => legal Kotlin but likely outside k0 subset
- tests/errors => illegal programs expected to produce errors
