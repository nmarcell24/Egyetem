// z3a7.ts
//
// TypeScript rewrite of z3a7.cpp
// LZW binary tree builder: reads a binary file bit-by-bit and builds a binary
// tree using the LZW algorithm, then reports tree depth, mean leaf depth, and
// standard deviation of leaf depths.
//
// Original C++ by Bátfai Norbert (GPLv3+)
// TypeScript port: 2024
//
// Usage: npx tsx z3a7.ts input.bin -o output.txt

import * as fs from "fs";
import * as path from "path";

// ---------------------------------------------------------------------------
// Node class (inner class equivalent of C++ Csomopont)
// ---------------------------------------------------------------------------

class Node {
  readonly char: string;
  private _zero: Node | null = null; // left / '0' child  (balNulla)
  private _one: Node | null = null;  // right / '1' child (jobbEgy)

  constructor(char: string = "/") {
    this.char = char;
  }

  zeroChild(): Node | null {
    return this._zero;
  }

  oneChild(): Node | null {
    return this._one;
  }

  setZeroChild(node: Node): void {
    this._zero = node;
  }

  setOneChild(node: Node): void {
    this._one = node;
  }
}

// ---------------------------------------------------------------------------
// LZWBinTree class
// ---------------------------------------------------------------------------

class LZWBinTree {
  private root: Node = new Node("/");
  private current: Node;

  // Traversal state (kept as instance fields like the C++ version)
  private depth: number = 0;
  private maxDepth: number = 0;
  private meanSum: number = 0;
  private meanCount: number = 0;
  private varianceSum: number = 0;
  private mean: number = 0;

  constructor() {
    this.current = this.root;
  }

  /**
   * Feed a single '0' or '1' character into the tree (equivalent to
   * operator<< in the C++ version).
   */
  push(bit: "0" | "1"): void {
    if (bit === "0") {
      if (!this.current.zeroChild()) {
        const newNode = new Node("0");
        this.current.setZeroChild(newNode);
        this.current = this.root;
      } else {
        this.current = this.current.zeroChild()!;
      }
    } else {
      if (!this.current.oneChild()) {
        const newNode = new Node("1");
        this.current.setOneChild(newNode);
        this.current = this.root;
      } else {
        this.current = this.current.oneChild()!;
      }
    }
  }

  // ---------------------------------------------------------------------------
  // Tree printing
  // ---------------------------------------------------------------------------

  /**
   * Returns a string representation of the tree (mirrors kiir() in C++).
   * Traversal order: right ('1') subtree first, then current node, then left ('0') subtree.
   */
  toString(): string {
    this.depth = 0;
    const lines: string[] = [];
    this.printNode(this.root, lines);
    return lines.join("\n") + "\n";
  }

  private printNode(node: Node | null, lines: string[]): void {
    if (node === null) return;

    this.depth++;
    this.printNode(node.oneChild(), lines);

    const indent = "---".repeat(this.depth);
    lines.push(`${indent}${node.char}(${this.depth - 1})`);

    this.printNode(node.zeroChild(), lines);
    this.depth--;
  }

  // ---------------------------------------------------------------------------
  // Statistics
  // ---------------------------------------------------------------------------

  /** Maximum depth of any node in the tree (equivalent to getMelyseg()). */
  getDepth(): number {
    this.depth = 0;
    this.maxDepth = 0;
    this.traverseDepth(this.root);
    return this.maxDepth - 1;
  }

  private traverseDepth(node: Node | null): void {
    if (node === null) return;
    this.depth++;
    if (this.depth > this.maxDepth) this.maxDepth = this.depth;
    this.traverseDepth(node.oneChild());
    this.traverseDepth(node.zeroChild());
    this.depth--;
  }

  /** Mean depth of all leaf nodes (equivalent to getAtlag()). */
  getMean(): number {
    this.depth = 0;
    this.meanSum = 0;
    this.meanCount = 0;
    this.traverseMean(this.root);
    this.mean = this.meanSum / this.meanCount;
    return this.mean;
  }

  private traverseMean(node: Node | null): void {
    if (node === null) return;
    this.depth++;
    this.traverseMean(node.oneChild());
    this.traverseMean(node.zeroChild());
    this.depth--;
    if (node.oneChild() === null && node.zeroChild() === null) {
      this.meanCount++;
      this.meanSum += this.depth;
    }
  }

  /** Standard deviation of leaf node depths (equivalent to getSzoras()). */
  getVariance(): number {
    this.mean = this.getMean();
    this.varianceSum = 0;
    this.depth = 0;
    this.meanCount = 0;
    this.traverseVariance(this.root);

    const variance =
      this.meanCount - 1 > 0
        ? Math.sqrt(this.varianceSum / (this.meanCount - 1))
        : Math.sqrt(this.varianceSum);

    return variance;
  }

  private traverseVariance(node: Node | null): void {
    if (node === null) return;
    this.depth++;
    this.traverseVariance(node.oneChild());
    this.traverseVariance(node.zeroChild());
    this.depth--;
    if (node.oneChild() === null && node.zeroChild() === null) {
      this.meanCount++;
      this.varianceSum += (this.depth - this.mean) ** 2;
    }
  }
}

// ---------------------------------------------------------------------------
// CLI / main
// ---------------------------------------------------------------------------

function usage(): void {
  console.log("Usage: ts-node z3a7.ts <in_file> -o <out_file>");
}

function main(): void {
  const args = process.argv.slice(2); // drop "node" and script path

  if (args.length !== 3) {
    usage();
    process.exit(-1);
  }

  const inFile = args[0];

  if (args[1] !== "-o") {
    usage();
    process.exit(-2);
  }

  const outFile = args[2];

  // Read input file as a raw buffer
  let buffer: Buffer;
  try {
    buffer = fs.readFileSync(inFile);
  } catch {
    console.log(`${inFile} does not exist...`);
    usage();
    process.exit(-3);
  }

  const tree = new LZWBinTree();

  // Skip the first line (up to and including the first 0x0a newline),
  // mirroring the C++ behaviour.
  let pos = 0;
  while (pos < buffer.length && buffer[pos] !== 0x0a) {
    pos++;
  }
  pos++; // skip the newline itself

  // Process the rest of the file
  let inComment = false;

  while (pos < buffer.length) {
    const b = buffer[pos++];

    if (b === 0x3e) {
      // '>' — start of a comment line
      inComment = true;
      continue;
    }

    if (b === 0x0a) {
      // newline — end of comment line
      inComment = false;
      continue;
    }

    if (inComment) continue;

    if (b === 0x4e) continue; // 'N' — skip

    // Process each bit of the byte, MSB first
    let byte = b;
    for (let i = 0; i < 8; i++) {
      tree.push(byte & 0x80 ? "1" : "0");
      byte = (byte << 1) & 0xff;
    }
  }

  // Build output string
  const output = [
    tree.toString(),
    `depth = ${tree.getDepth()}`,
    `mean = ${tree.getMean()}`,
    `var = ${tree.getVariance()}`,
    "",
  ].join("\n");

  fs.writeFileSync(outFile, output, "utf8");
}

main();