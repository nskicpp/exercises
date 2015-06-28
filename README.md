Niedzielski C++ Course -- Exercises Repository
==============================================
Instructor:  Patrick M. Niedzielski <patrick@pniedzielski.net>

This repository contains all student and instructor submissions for
exercises in the course.  Please fork this repository and also work in
your own folder!

There will be an initial `.gitkeep` file in each of your directories.
This is just so we can have the initial empty directory in a git
repository.  Feel free to delete it once you've gotten started.

Submitting an Exercise
----------------------

  * Even though the exercises are very simple programs, we want to get
    in a good habit and get experience with CMake.  So, your exercises
    should be a single project managed by CMake (i.e., one
    `CMakeLists.txt`).

  * All exercises should include automated test(s)!  How many you need
    is your decision, but make sure you're able to defend that!
    Whether you write the test case(s) first (à la Test Driven
    Development) or do so after is up to you.  Your final product is
    more important than the way you get there.  We will be getting a
    little more formal about this later and we'll start to look at how
    to test software.

    The tests should run when you type `make test`, so you'll have to
    include that in your CMake file.  See [Lesson 3][lesson-3] for an
    example of how to do this. _[As of writing, this link is broken.
    Check back soon!_]

  * Don't commit generated files (`.o`, the final executables, etc.)!
    Just commit source files, CMake files, and anything else that's
    needed to build and test the exercises.

  * Write your exercises in different files with good, useful names!
    As exercises get more complicated, you may even find breaking them
    into separate directories will help.

  * __Make sure it compiles!__ Test on both Clang and GCC.

  * When your exercises is done, submit a pull request.  This is the
    beginning of a dialogue with the instructor and the other
    students.  Chiming in on other pull requests is encouraged, and
    even reading them, you may find a useful idea you hadn't thought
    of before.  You will have to defend your decisions, especially in
    less trivial exercises, and you will at points have to go back and
    fix mistakes you have made or make your code clearer and more
    idiomatic.

  * Feel free to consult other students or any documentation you find
    online, but know that you will need to defend your decisions
    later.  Good reasoning behind any answer is much more illuminating
    than a good answer, and there are multiple good answers as well!
    So, try to do it on your own, and then see what others are doing
    when you finish or if you get stuck.


[lesson-3]: https://github.com/nskicpp/writeups/blob/dev-environment/lessons/03-dev-environment.md
