pipeline {
    agent any

    stages {
        stage('Project setup') {
            steps {
                sh 'git rm --cached common'
                sh 'make update'
            }
        }

        stage('Project compilation') {
            agent {
                docker {
                    image 'epitechcontent/epitest-docker'
                }
            }

            steps {
                sh 'make clean'
                sh 'make'
                sh 'make fclean'
            }
        }

        stage('Project tests') {
            agent {
                docker {
                    image 'epitechcontent/epitest-docker'
                }
            }

            steps {
                sh 'make tests_run'
            }
        }
    }
}
