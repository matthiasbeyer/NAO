#ifndef __ALGO_DRAW_H__
#define __ALGO_DRAW_H__

namespace algo {

    class Draw {

        private:

            signed short __certainty;

        public:

            Draw(signed short certainty);

            operator signed short();
            operator bool();

            signed short certainty();   // alias for operator char()
            bool doDraw();              // alias for operator bool()

    };

}

#endif