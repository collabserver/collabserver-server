# CRDT Examples
Examples of CRDTs implementations in C. (For educational purpose only).


# Features
- CvRDT_GIntCounter: Grow-only Integer Counter (State-based)
- CvRDT_GIntVector: Grow-only Integer Vector (State-based)
- CvRDT_PNIntCounter: Increment / Decrement Integer Counter (State-based)


# State-based object (CvRDT)
    State CvRDT is defined by (S s0 q u m)
        S   -> Global State
        s0  -> State at beginning
        q   -> Query method
        u   -> Update method
        m   -> Merge method


# Papers and resources
- https://pages.lip6.fr/Marc.Shapiro/papers/CRDTs_SSS-2011.pdf
