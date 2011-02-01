Source Code Organization Example
================================

Getting the files:
------------------

On the lab computer, you can use:
<pre><code>
git clone git://github.com/cwru-eecs338/organization_example.git
</code></pre>

Otherwise, you can download and extract the tarball using:
<pre><code>
wget --no-check-certificate -q -O - https://github.com/cwru-eecs338/organization_example/tarball/master | tar -xzvf -
</code></pre>

How to use:
-----------

1. Compile using <code>make</code>
2. Run the executable file, <code>main</code>
3. A parent process forks several children, some of which finish successfully

What to learn:
--------------

* Sometimes it is convenient to split code into several files to separate functionality
* In C, header files and include statements are used to reference code in other files
* Function prototypes must be defined before a function is referenced
* The <code>gcc</code> compiler will compile and link multiple source files that
  are specified as arguments

Other lessons:
--------------

* How to fork multiple children in a <code>for</code> loop
* Getting the status of children from the <code>wait()</code> call
* The distinction between <code>exit()</code> and <code>_exit()</code>
* Using <code>sleep()</code> to impose an ordering on events (not the best
  solution, since it does not guarantee the ordering we want)
