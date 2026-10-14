#ifndef _IN_RAGDOLLSKIN_H
#define _IN_RAGDOLLSKIN_H

/* Retain influences only from the vertex's strongest connected piece.
 * Uncut rigs have one piece, so their weights are not changed. */
static inline int ragdollSkinWeights(const unsigned char *bones, const float *weights,
        int count, const short *pieces, int numpieces, float *out)
{
    int best = -1, owner = 0;
    float strongest = -1.0f, sum = 0.0f;
    for (int j = 0; j < 3; j++) out[j] = 0.0f;
    for (int j = 0; j < count && j < 3; j++) {
        if (bones[j] < numpieces && weights[j] > 0.0f) {
            float score = 0.0f;
            for (int k = 0; k < count && k < 3; k++) {
                if (bones[k] < numpieces && pieces[bones[k]] == pieces[bones[j]] && weights[k] > 0.0f)
                    score += weights[k];
            }
            if (score > strongest) {
                strongest = score; best = j; owner = pieces[bones[j]];
            }
        }
    }
    if (best < 0) return -1;
    for (int j = 0; j < count && j < 3; j++) {
        if (bones[j] < numpieces && pieces[bones[j]] == owner && weights[j] > 0.0f) {
            out[j] = weights[j]; sum += weights[j];
        }
    }
    if (sum > 0.0f) {
        for (int j = 0; j < 3; j++) out[j] /= sum;
    } else {
        out[best] = 1.0f;
    }
    return owner;
}

static inline int ragdollSkinTriangle(const short *pieces, int count, int a, int b, int c)
{
    return a >= 0 && b >= 0 && c >= 0 && a < count && b < count && c < count
        && pieces[a] >= 0 && pieces[a] == pieces[b] && pieces[a] == pieces[c];
}
#endif
