https://www.learncpp.com/cpp-tutorial/variable-assignment-and-initialization/

Une initialisation de variable signifie qu’une valeur doit être donnée au moment de la définition de la variable. Une
affectation correspond à l’utilisation de l’opérateur = en dehors d’une initialisation. Si une variable n’est pas initialisée, sa valeur n’est pas connue jusqu’à sa première affectation. Certains compilateurs bloquent (en provoquant
une erreur), l’utilisation d’une variable non-initialisée ou non-affectée. Le C++11 permet aussi les initialisations
avec accolades (initialisation uniforme). Attention, avec l’instruction auto x={3.14};, x serait du type std::
initiliazer<double> et non de type double. Ce n’est pas le cas avec l’instruction auto x{3.14}; où x est
bien de type double.


Remarque : il y a une différence profonde entre l’affectation et l’initialisation. Cette différence est beaucoup plus
visible lorsque des objets sont manipulés. Notamment, lors de l’initialisation d’un objet, c’est un constructeur de la
classe de cet objet qui est appelé, alors que c’est la surcharge de l’opérateur = qui est appelé lors d’une affectation.



