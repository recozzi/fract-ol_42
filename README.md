<h1>Fract-ol</h1>
The first graphical project at 42 school that explores the creation of visually stunning fractal images, leveraging the power of complex numbers within an iterative mathematical construct.
<h2>Overview</h2>
Fractals are fascinating and intricate patterns that exhibit self-similarity at various scales.
Students at 42 school delve into the world of complex numbers, used as input for an iterative algorithm, where each iteration calculates a new value based on the previous one.
By repeating this process, students can explore the behavior of the complex numbers within the algorithm and observe how the patterns evolve over time.
The project encourages students to experiment with different mathematical constructs, such as the Mandelbrot set or the Julia set, which are famous examples of fractals.
<h2>How To Use</h2>
<ol>
  <li>Clone the repository:</li>
  <pre><code>git clone https://github.com/recozzi/fract-ol_42.git</code></pre>
  <li>move to folder Libft:</li>
  <pre><code>cd fract-ol</code></pre>
  <li>Compile the library with Makefile rule:</li>
  <pre><code>make</code></pre>
  <li>Make sure that you have all the dependencies needed for minilibx, if you are not sure, check <a href="https://harm-smits.github.io/42docs/libs/minilibx">here</a> on how to install them.</li>
  <li>Now you are ready to visualize fractals. Available fractals: Mandelbrot, Julia and Burningship.</li>
  To launch Mandelbrot:
  <pre><code> ./fractol mandelbrot</code></pre>
  To launch Burningship:
   <pre><code>./fractol burningship</code></pre>
  To launch Julia:
   <pre><code>./fractol julia x y</code></pre>
  x and y are complex numbers between -2.000 and 2.000 not included.
</ol>
<h2>Info</h2>
For more information about this project, please read the subject file <a href="https://github.com/recozzi/fract-ol_42/blob/main/en.subject.pdf">here</a>.
<h2>License</h2>
See <a href="https://github.com/recozzi/fract-ol_42/blob/main/LICENSE">License</a>.
