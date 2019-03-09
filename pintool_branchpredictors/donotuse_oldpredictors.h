
/******************************************

// DO NOT USE, THESE ARE OLD VERSIONS
// USE THE ONES FROM custom_predictors.h

********************************************/

/*

// local history predictor without using existing nbit predictors
class LocalHistoryPredictor : public BranchPredictor
{
public:
    LocalHistoryPredictor(int bht_entries_, int bht_bits_, int pht_entries_, int nbits)
    : BranchPredictor(), pht_entries(pht_entries_), pht_bits(nbits), bht_entries(bht_entries_), bht_bits(bht_bits_) 
    {
        bht_entries = bht_entries_;
        bht_bits = bht_bits_;
        bhrmax = 1 << bht_bits;
        countermax = (1 << pht_bits) - 1;

        // create empty tables
        BHT = new int[bht_entries];
        PHT = new int*[pht_entries];
        for (int i = 0; i < pht_entries; i++) {
            PHT[i] = new int[bhrmax];
            memset(PHT[i], 0, bhrmax * sizeof(int));
        }
    }
    
    ~LocalHistoryPredictor() {
        for (int i = 0; i < pht_entries; i++) {
            delete PHT[i];
        }
        delete PHT;
        delete BHT;
    }

    // return true if the corresponding counter has MSB == 1
    virtual bool predict(ADDRINT ip, ADDRINT target) {
        int counterMSB = PHT[ip % pht_entries][BHT[ip % bht_entries]] >> (pht_bits-1);
        return counterMSB != 0;
    }

    // update
    virtual void update(bool predicted, bool actual, ADDRINT ip, ADDRINT target) {
        updateCounters(predicted, actual);

        // update counter
        int & bhr = BHT[ip % bht_entries];
        int & counter = PHT[ip % pht_entries][bhr];
        if ((predicted == actual) && (counter < countermax))
            counter++;
        else if ((predicted != actual) && (counter > 0))
            counter--;

        // last, update bhr
        // bhr = ((bhr << 1) % bhrmax) | (predicted==actual));
        bhr = (bhr << 1) % bhrmax; // shift left and drop MSB
        if (actual) bhr++;
    }

    virtual string getName() {
        ostringstream st;
        int size = pht_entries * pht_bits * (1 << bht_bits) + bht_entries*bht_bits;
        size = size >> 10;
        st << "LocalHistory-" << size << "K-PHT(" << pht_entries << "," << pht_bits << ")-BHT(" << bht_entries << "," << bht_bits << ")";
        return st.str();
    }

protected:
    int pht_entries, pht_bits;  // entries and bits per entry
    int bht_entries, bht_bits;  // entries and bits per entry

private:
    int *BHT;                   // use x = BHT[ip % bht_entries]
    int **PHT;                  // use PHT[ip % pht_entries][x]

    int bhrmax;                 // max entry for BHT
    int countermax;             // max counter value for PHT entries
};
*/

/*
// OLD OLD OLD OLD
// DONT USE
// for some reason gives really bad prediction results
// global history predictor (m, n) with 2^k entries
class _GlobalHistoryPredictor : public BranchPredictor
{
public:
    _GlobalHistoryPredictor(int bhr_length, int nbits, int index_bits)
    : BranchPredictor(), m(bhr_length), n(nbits), k(index_bits)
    {
        pcmax = 1 << k;
        bhrmax = 1 << m;
        countermax = (1 << n) - 1;

        // initial value for BHR, arbitrary
        bhr = 0;

        // create empty prediction history table
        // access with TABLE[pcbits][bhr];
        TABLE = new int*[pcmax];
        for (int i = 0; i < pcmax; i++) {
            TABLE[i] = new int[bhrmax];
            memset(TABLE[i], 0, bhrmax * sizeof(int));
        }
    }
    
    ~_GlobalHistoryPredictor() {
        delete TABLE;
    }

    // return true if the corresponding counter has MSB == 1
    virtual bool predict(ADDRINT ip, ADDRINT target) {
        int counterMSB = TABLE[ip % pcmax][bhr] >> (n-1);
        return counterMSB != 0;
    }

    // update
    virtual void update(bool predicted, bool actual, ADDRINT ip, ADDRINT target) {
        updateCounters(predicted, actual);

        // update counter
        int & counter = TABLE[ip % pcmax][bhr];
        if ((predicted == actual) && (counter < countermax))
            counter++;
        else if ((predicted != actual) && (counter > 0))
            counter--;

        // last, update bhr
        // bhr = ((bhr << 1) % bhrmax) | (predicted==actual));
        bhr = (bhr << 1) % bhrmax; // shift left and drop MSB
        if (predicted == actual) bhr++;
    }

    virtual string getName() {
        ostringstream st;
        st << "GlobalHistory-" << pcmax << "entries-(" << m << "," << n << ")";
        return st.str();
    }

private:
    int m, n, k;
    int pcmax, bhrmax;
    int countermax;

    int bhr;

    int **TABLE; // use TABLE[ip % pcmax][bhr];
};
*/