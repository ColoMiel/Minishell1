🐚 Minishell1
        - Minishell1 est un interpréteur de commandes UNIX simplifié, inspiré du shell tcsh. Ce projet fait partie du cursus Epitech et constitue une étape clé pour la réalisation d'un shell plus avancé, comme le 42sh.

📜 Description
        - L'objectif est de créer un shell capable d'exécuter des commandes basiques, d'afficher un prompt interactif, et de gérer les variables d'environnement. Il doit fonctionner comme un shell standard pour des commandes simples.

⚙️ Fonctionnalités
        - Affichage d'un prompt ($> par exemple).
        - Exécution des commandes système via execve.
        - Gestion des chemins via la variable PATH.
        - Gestion des erreurs avec messages sur la sortie d'erreur.
        - Implémentation des builtins suivants :
        - cd : changer de répertoire.
        - env : afficher les variables d'environnement.
        - setenv : ajouter ou modifier une variable d'environnement.
        - unsetenv : supprimer une variable d'environnement.
        - exit : quitter le shell.
        - Exécution de plusieurs commandes séparées par des points-virgules (;).
        - Affichage d'un message en cas de segfault d'un programme exécuté.

Compiler le projet avec "make";
lancer le projet "./mysh"

🤝 Contributeurs
        - Hatim Ouaadi
