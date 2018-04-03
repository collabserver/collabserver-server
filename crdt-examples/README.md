# CRDT Examples
Examples of CRDTs implementations in C++ (For educational purpose only).


# Features
- CvRDT_GCounterInt: Grow-only Integer Counter (State-based)
- CvRDT_GVectorInt: Grow-only Integer Vector (State-based)
- CvRDT_PNCounterInt: Increment / Decrement Integer Counter (State-based)
- CvRDT_PNVectorInt: Increment / Decrement Integer Vector (State-based)
- CvRDT_GSetInt: Grow-only Integer set (State-based)
- CvRDT_USetInt: Grow-only Integet 2P-Set (State-based)


# State-based object (CvRDT)
    State CvRDT is defined by (S s0 q u m)
        S   -> Global State
        s0  -> State at beginning
        q   -> Query method
        u   -> Update method
        m   -> Merge method


# Papers and resources
- https://pages.lip6.fr/Marc.Shapiro/papers/CRDTs_SSS-2011.pdf
