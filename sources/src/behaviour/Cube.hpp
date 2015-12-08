namespace nao {

    /**
     * Class to represent the found cube
     */
    struct Cube {
        Cube();
        ~Cube();

        operator bool();
        operator =(const Cube& other);
    };

    /**
     * Class to represent the found and color-analyzed cube
     */
    struct AnalyzedCube : public Cube {
        operator nao::algo::Card(); //cast to Card instance
    };

}
